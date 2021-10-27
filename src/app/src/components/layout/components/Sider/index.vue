<template>
    <n-layout-sider
        bordered
        show-trigger
        collapse-mode="width"
        :collapsed-width="64"
        :width="240"
        :native-scrollbar="false"
        style="max-height: 100%;"
    >
        <n-menu
            :collapsed-width="64"
            :collapsed-icon-size="22"
            :options="menuOptions"
        />
    </n-layout-sider>
</template>

<script>
import {h, defineComponent} from 'vue'
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
                        name: 'toContentHeader',
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
                        name: 'toContentHeader',
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

export default defineComponent({
    name: "Sider",
    setup() {
        return {
            menuOptions
        }
    }
})
</script>

<style scoped>

</style>
