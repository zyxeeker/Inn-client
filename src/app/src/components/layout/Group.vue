<template>
    <n-layout position="absolute" content-style="display:flex;flex-direction: column;overflow:hidden;" has-sider>
        <n-layout-sider
            bordered
            show-trigger
            collapse-mode="width"
            :collapsed-width="64"
            :width="180"
            :native-scrollbar="false"
            style="max-height: 100%;"
        >
            <n-menu
                :collapsed-width="64"
                :collapsed-icon-size="22"
                :options="menuOptions"
            />
        </n-layout-sider>

        <n-layout content-style="display:flex;flex-direction: column;overflow:hidden;">

            <router-view name="Content" v-slot="{Component}">
                <transition enter-active-class="animate__animated animate__bounceInDown"
                            leave-active-class="animate__animated animate__bounceOutDown" mode="out-in">
                    <!--                        <keep-alive exclude="Home,channel">-->
                    <component :key="$route.hash" :is="Component"/>
                    <!--                        </keep-alive>-->
                </transition>
            </router-view>
        </n-layout>

    </n-layout>
</template>

<script>
import {h} from 'vue'
import {RouterLink} from 'vue-router'
import {NIcon} from 'naive-ui'
import {Signature} from "@vicons/fa"

const menuOptions = [
    {
        label: () =>
            h(
                RouterLink,
                {
                    to: {
                        name: 'switchChannel',
                        hash: '#home',
                        params: {
                            title: '大厅',
                            des: '欢迎来到大厅！'
                        }
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
                        name: 'switchChannel',
                        hash: '#test',
                        params: {
                            title: 'TEST',
                            des: '欢迎来到TEST！'
                        }
                    }
                },
                {default: () => 'TEST'}
            ),
        key: 'TEST',
        icon: renderIcon(Signature)
    }
]

function renderIcon(icon) {
    return () => h(NIcon, null, {default: () => h(icon)})
}

export default {
    name: "Group",
    setup() {
        return {
            menuOptions
        }
    }
}
</script>

<style scoped>

</style>
