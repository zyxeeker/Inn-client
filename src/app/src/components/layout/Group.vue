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
                :options="channels"
            />
        </n-layout-sider>
        <n-layout content-style="display:flex;flex-direction: column;overflow:hidden;" sider-placement="right"
                  has-sider>
            <router-view name="Content" v-slot="{Component}">
                <transition enter-active-class="animate__animated animate__bounceInDown"
                            leave-active-class="animate__animated animate__bounceOutDown" mode="out-in">
                    <!--                        <keep-alive exclude="Home,channel">-->
                    <component :key="$route.hash" :is="Component"/>
                    <!--                        </keep-alive>-->
                </transition>
            </router-view>

            <n-layout-sider
                bordered
                show-trigger
                collapse-mode="width"
                :collapsed-width="0"
                :width="180"
                :native-scrollbar="false"
                style="max-height: 100%;"
            >
                <n-menu
                    :options="friends"
                />
            </n-layout-sider>
        </n-layout>

    </n-layout>
</template>

<script>
import {h} from 'vue'
import {RouterLink} from 'vue-router'
import {NIcon} from 'naive-ui'
import {Signature} from "@vicons/fa"

const friends = [
    {
        label: '大厅',
        key: 'downtown',
        icon: renderIcon(Signature)
    },
    {
        label: 'TEST',
        key: 'TEST',
        icon: renderIcon(Signature)
    }
]

function renderIcon(icon) {
    return () => h(NIcon, null, {default: () => h(icon)})
}

export default {
    name: "Group",
    data() {
        return {
            channels: []
        }
    },
    setup() {
        return {
            friends
        }
    },
    mounted() {
        window.updateChannel = this.updateChannel
    },
    methods: {
        updateChannel(value) {
            let data = JSON.parse(value);
            for (let i = 0, l = data['data'].length; i < l; ++i) {
                let item = data['data'][i]
                this.channels.push({
                    label: () =>
                        h(
                            RouterLink,
                            {
                                to: {
                                    name: 'switchChannel',
                                    hash: item['hash'],
                                    params: {
                                        title: item['params']['title'],
                                        des: item['params']['des']
                                    }
                                }
                            },
                            {default: () => item['name']}
                        ),
                    key: item['name'],
                    icon: renderIcon(Signature)
                })
            }
        }
    }
}
</script>

<style scoped>

</style>
