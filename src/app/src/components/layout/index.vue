<template>
    <n-layout position="static" has-sider>
        <n-layout-sider
            bordered
            collapse-mode="width"
            :collapsed-width="64"
            :native-scrollbar="false"
            style="max-height: 100%;"
            :collapsed="true"
        >
            <n-menu
                :collapsed-width="64"
                :collapsed-icon-size="22"
                :options="menuOptions"
            />
        </n-layout-sider>

        <n-layout style="height: 100vh;">
            <n-layout-header style="height: 30px;" bordered>
            </n-layout-header>
            <n-layout position="absolute" style="top: 30px;overflow:hidden;" has-sider>
                <n-layout ref="container" content-style="display:flex;flex-direction: column;overflow:hidden;">
                    <!--                    <Group/>-->
                    <router-view name="Room" v-slot="{Component}">
                        <transition enter-active-class="animate__animated animate__bounceInDown"
                                    leave-active-class="animate__animated animate__bounceOutDown" mode="out-in">
                            <!--                        <keep-alive exclude="Home,channel">-->
                            <component :key="$route.params.id" :is="Component"/>
                            <!--                        </keep-alive>-->
                        </transition>
                    </router-view>
                </n-layout>
            </n-layout>
        </n-layout>
    </n-layout>
</template>

<script>
import {h} from 'vue'
import {RouterLink} from 'vue-router'
import {NIcon} from 'naive-ui'
import {Signature} from "@vicons/fa"

function renderIcon(icon) {
    return () => h(NIcon, null, {default: () => h(icon)})
}

const menuOptions = [
    {
        label: () =>
            h(
                RouterLink,
                {
                    to: {
                        path: '/group/0',
                    }
                },
                {default: () => '大厅'}
            ),
        key: 'downtown',
        icon: renderIcon(Signature)
    },
    {
        label: () =>
            h(
                RouterLink,
                {
                    to: {
                        path: '/group/1',
                    }
                },
                {default: () => 'TEST'}
            ),
        key: 'TEST',
        icon: renderIcon(Signature)
    }
]
export default {
    name: "Layout",
    // components: {channel, Sider},
    setup() {
        return {
            menuOptions
        }
    },
    watch: {
        '$route'(to) {
            if (to.name === '') {
                console.log(to.query)     // 在此调用函数
            }
        }
    },
    computed: {
        key() {
            return this.$route.name !== undefined ? this.$route.name + new Date().getTime().toString() : this.$route + new Date().getTime().toString();
        },
    },

}
</script>

<style scoped>

</style>
